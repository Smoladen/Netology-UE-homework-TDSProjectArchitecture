// LeaveMeAlone Game by Netologya. All rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class LeaveMeAloneTarget : TargetRules
{
	public LeaveMeAloneTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "LeaveMeAlone" } );
	}
}
