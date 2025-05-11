// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialInstanceDynamicChange.h"

#include "SceneRenderTargetParameters.h"


// Sets default values
AMaterialInstanceDynamicChange::AMaterialInstanceDynamicChange() :
	Mesh(CreateDefaultSubobject<UStaticMeshComponent>("Mesh"))
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set 'Mesh' as root component
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AMaterialInstanceDynamicChange::BeginPlay()
{
	// Call super class method
	Super::BeginPlay();

	// Get material in first slot
	Material = Mesh->GetMaterial(0);

	// Make new dynamic material instance from 'Material'
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);

	// Set material of 'Mesh' as 'DynamicMaterial'
	Mesh->SetMaterial(0, DynamicMaterial);

	// Set parameters of 'DynamicMaterial'
	DynamicMaterial->SetVectorParameterValue(TEXT("Colour"), FLinearColor::Green);
}

// Called every frame
void AMaterialInstanceDynamicChange::Tick(float DeltaTime)
{
	// Call super class method
	Super::Tick(DeltaTime);
}

