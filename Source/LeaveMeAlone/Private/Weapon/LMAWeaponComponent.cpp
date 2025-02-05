// LeaveMeAlone Game by Netologya. All rights Reserved

DEFINE_LOG_CATEGORY_STATIC(LogWeapon, All, All);
#include "Weapon/LMAWeaponComponent.h"
#include "Weapon/LMABaseWeapon.h"
#include "GameFramework/Character.h" 
#include "Animations/LMAReloadFinishedAnimNotify.h"

ULMAWeaponComponent::ULMAWeaponComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

}


void ULMAWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
	InitAnimNotify();
}


void ULMAWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void ULMAWeaponComponent::SpawnWeapon()
{
	Weapon = GetWorld()->SpawnActor<ALMABaseWeapon>(WeaponClass);
	if (Weapon)
	{
		const auto Character = Cast<ACharacter>(GetOwner());
		if (Character)
		{
			FAttachmentTransformRules
				AttachmentRules(EAttachmentRule::SnapToTarget, false);
			Weapon->AttachToComponent(Character->GetMesh(), AttachmentRules,"r_Weapon_Socket");
		}
	}
}
void ULMAWeaponComponent::StartFire()
{
	if (Weapon && !AnimReloading)
	{
		Weapon->StartFire();
	}
}

void ULMAWeaponComponent::StopFire()
{
	if (Weapon)
	{
		Weapon->StopFire();
	}
}
void ULMAWeaponComponent::InitAnimNotify()
{
	if (!ReloadMontage) {
		return;
	}
	const auto NotifiesEvents = ReloadMontage->Notifies;
	for (auto NotifyEvent : NotifiesEvents)
	{
		auto ReloadFinish = Cast<ULMAReloadFinishedAnimNotify>(NotifyEvent.Notify);
		if (ReloadFinish)
		{
			ReloadFinish->OnNotifyReloadFinished.AddUObject(this,&ULMAWeaponComponent::OnNotifyReloadFinished);
			break;
		}
	}
}
void ULMAWeaponComponent::OnNotifyReloadFinished(USkeletalMeshComponent*SkeletalMesh)
{
	UE_LOG(LogWeapon, Display, TEXT("Reload animation finished!"));

	const auto Character = Cast<ACharacter>(GetOwner());
	if (Character->GetMesh() == SkeletalMesh)
	{
		AnimReloading = false;
		if (Weapon) {
			Weapon->ChangeClip();
		}
	}
}
bool ULMAWeaponComponent::CanReload() const
{
	return !AnimReloading;
}
void ULMAWeaponComponent::Reload()
{
	if (!CanReload()) return;

	AnimReloading = true;
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	Character->PlayAnimMontage(ReloadMontage);
}
