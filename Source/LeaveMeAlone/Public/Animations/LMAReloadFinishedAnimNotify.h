// LeaveMeAlone Game by Netologya. All rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "LMAReloadFinishedAnimNotify.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNotifyReloadFinishedSignature,USkeletalMeshComponent*);

UCLASS()
class LEAVEMEALONE_API ULMAReloadFinishedAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	

public:

	FOnNotifyReloadFinishedSignature OnNotifyReloadFinished;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase*Animation) override;
};
