// Marcin Staniek Game Dev Course 2020

using UnrealBuildTool;
using System.Collections.Generic;

public class BattleTankTarget : TargetRules
{
	public BattleTankTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Game;
		ExtraModuleNames.AddRange( new string[] { "BattleTank" } );
	}
}
