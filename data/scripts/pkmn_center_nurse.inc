EventScript_PkmnCenterNurse:: @ 81A6578
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

EventScript_PkmnCenterNurse_HealPkmn:: @ 81A65B8
	incrementgamestat GAME_STAT_USED_POKECENTER
	message Text_TakeYourPkmnForFewSeconds
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	call EventScript_PkmnCenterNurse_ReturnPkmn
	end

EventScript_PkmnCenterNurse_TakeAndHealPkmn:: @ 81A65CE
	applymovement VAR_LAST_TALKED, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Movement_WalkInPlaceFastestDown
	waitmovement 0
	special HealPlayerParty
	return

EventScript_PkmnCenterNurse_ReturnPkmn:: @ 81A661D
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	release
	return

Movement_Bow:: @ 81A666C
	nurse_joy_bow
	delay_4
	step_end
