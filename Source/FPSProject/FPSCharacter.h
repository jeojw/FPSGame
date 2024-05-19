// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "FPSProjectile.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FPSPROJECT_API AFPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // �� ĳ���� ������Ƽ�� ����Ʈ�� ����
    AFPSCharacter();

protected:
    // ���� ���� �� �Ǵ� ���� �� ȣ��
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, Category = Projectile)
    TSubclassOf<class AFPSProjectile> ProjectileClass;

public:
    // ��� �����ӿ��� ȣ��
    virtual void Tick(float DeltaTime) override;

    // �Լ� ����� �Է¿� ���ε��ϱ� ���� ȣ��
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


    // ������ �̵� �� �ڷ� �̵� �Է��� ó���մϴ�.
    UFUNCTION()
    void MoveForward(float Value);

    // ������ �̵� �� ���� �̵� �Է��� ó���մϴ�.
    UFUNCTION()
    void MoveRight(float Value);

    UFUNCTION()
    void StartJump();

    UFUNCTION()
    void StopJump();

    UPROPERTY(VisibleAnywhere)
    UCameraComponent* FPSCameraComponent;

    UPROPERTY(VisibleDefaultsOnly, Category = FPSCharacter)
    USkeletalMeshComponent* FPSMesh;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = Weapon)
    USkeletalMeshComponent* GunMesh;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = FPSWeapon)
    USkeletalMeshComponent* FPSGunMesh;

    UFUNCTION()
    void Fire();

    UFUNCTION()
    void StopFire();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
    FVector MuzzleOffset;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Animation)
    bool bIsMoving;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Animation)
    bool bIsFiring;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Animation)
    bool bIsJumpStart;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Animation)
    bool bIsJumping;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Animation)
    bool bIsJumpEnd;

    FTimerHandle TimerHandle_StopFiring;
};

