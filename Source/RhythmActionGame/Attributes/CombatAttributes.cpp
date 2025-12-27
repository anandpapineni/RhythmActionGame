// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatAttributes.h"

UCombatAttributes::UCombatAttributes()
{
	Health.SetBaseValue(100.f);
	Health.SetCurrentValue(100.f);
 
	AttackPower.SetBaseValue(10.f);
	AttackPower.SetCurrentValue(10.f);
}
