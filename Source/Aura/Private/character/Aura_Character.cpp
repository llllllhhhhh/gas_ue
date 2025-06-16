// Fill out your copyright notice in the Description page of Project Settings.


#include "character/Aura_Character.h"

#include "GameFramework/CharacterMovementComponent.h"

AAura_Character::AAura_Character()
{
	GetCharacterMovement()->bOrientRotationToMovement = true; //����Ϊtrue����ɫ�����ƶ��ķ�����ת
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f); //��ת����
	GetCharacterMovement()->bConstrainToPlane = true; //Լ����ƽ��
	GetCharacterMovement()->bSnapToPlaneAtStart = true; //����������һ��Ϊtrue���Ҵ�������Ϊtrue�����ڿ�ʼʱ��������

	//����ʹ�ÿ�����ѡ��Pitch��Yaw��Roll��ֵ��
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}
