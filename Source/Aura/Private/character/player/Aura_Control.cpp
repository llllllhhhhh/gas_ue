// Fill out your copyright notice in the Description page of Project Settings.


#include "character/player/Aura_Control.h"


#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


AAura_Control::AAura_Control()
{
	bReplicates = true;
}

void AAura_Control::BeginPlay()
{
	Super::BeginPlay();
	check(AuraMapping); //�ж��Ƿ����

	//�ӱ��ؽ�ɫ���ϻ�ȡ��������ϵͳ
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem); //�����ϵͳ�Ƿ����
	Subsystem->AddMappingContext(AuraMapping, 0); //���Դ��ڶ������ӳ�䣬�������ȼ�����

	bShowMouseCursor = true; //��Ϸ���Ƿ���ʾ�����
	DefaultMouseCursor = EMouseCursor::Default; //��������ʽ

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); //������������ӿ���
	InputModeData.SetHideCursorDuringCapture(false); //��걻����ʱ�Ƿ�����
	SetInputMode(InputModeData); //���ø�������


}

void AAura_Control::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent); //��ȡ����ǿ�������

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAura_Control::Move); //���ƶ��¼�
}

void AAura_Control::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>(); //��ȡ���������2ά����ֵ
	const FRotator Rotation = GetControlRotation(); //��ȡ��������ת
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f); //ͨ���������Ĵ�ֱ���򴴽�һ����תֵ���������³�������ҳ���

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); //��ȡ��������ϵ����ǰ��ֵ��-1��1
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); //��ȡ��������ϵ�����ҵ�ֵ��-1��1

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}