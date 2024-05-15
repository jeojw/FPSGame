// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
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

    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    USkeletalMeshComponent* FPSMesh;

    UFUNCTION()
    void Fire();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
    FVector MuzzleOffset;
};

