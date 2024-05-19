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
    // 이 캐릭터 프로퍼티의 디폴트값 설정
    AFPSCharacter();

protected:
    // 게임 시작 시 또는 스폰 시 호출
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, Category = Projectile)
    TSubclassOf<class AFPSProjectile> ProjectileClass;

public:
    // 모든 프레임에서 호출
    virtual void Tick(float DeltaTime) override;

    // 함수 기능을 입력에 바인딩하기 위해 호출
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


    // 앞으로 이동 및 뒤로 이동 입력을 처리합니다.
    UFUNCTION()
    void MoveForward(float Value);

    // 오른쪽 이동 및 왼쪽 이동 입력을 처리합니다.
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

