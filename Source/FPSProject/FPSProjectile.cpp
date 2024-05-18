// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile()
{
    // 이 액터가 프레임마다 Tick()을 호출하도록 설정합니다.  필요 없는 경우 퍼포먼스 향상을 위해 이 설정을 끌 수 있습니다.
    PrimaryActorTick.bCanEverTick = true;

    if (!RootComponent)
    {
        RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
    }

    if (!CollisionComponent)
    {
        // 스피어를 단순 콜리전 표현으로 사용합니다.
        CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
        // 스피어의 콜리전 프로파일 이름을 'Projectile'로 설정합니다.
        CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
        // 컴포넌트가 어딘가에 부딪힐 때 호출되는 이벤트입니다.
        CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
        // 스피어의 콜리전 반경을 설정합니다.
        CollisionComponent->InitSphereRadius(15.0f);
        // 루트 컴포넌트가 콜리전 컴포넌트가 되도록 설정합니다.
        RootComponent = CollisionComponent;
    }

    if (!ProjectileMovementComponent)
    {
        // 이 컴포넌트를 사용하여 이 발사체의 이동을 주도합니다.
        ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
        ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
        ProjectileMovementComponent->InitialSpeed = 12000.0f;
        ProjectileMovementComponent->MaxSpeed = 12000.0f;
        ProjectileMovementComponent->bRotationFollowsVelocity = true;
        ProjectileMovementComponent->bShouldBounce = true;
        ProjectileMovementComponent->Bounciness = 0.3f;
        ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
    }

    if (!ProjectileMeshComponent)
    {
        ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
        static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("/Script/Engine.StaticMesh'/Game/Sphere.Sphere'"));
        if (Mesh.Succeeded())
        {
            ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
        }

        static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("/Script/Engine.Material'/Game/SphereMaterial.SphereMaterial'"));
        if (Material.Succeeded())
        {
            ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
        }
        ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
        ProjectileMeshComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
        ProjectileMeshComponent->SetupAttachment(RootComponent);
    }

    // 3초 후 발사체를 제거합니다.
    InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
    {
        OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 10.0f, Hit.ImpactPoint);
    }
    Destroy();
}


