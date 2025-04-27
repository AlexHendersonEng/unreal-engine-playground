// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPluginActor.h"
#include "Engine/Engine.h"
#include "../../ThirdParty/MyLibrary/MyStaticLibrary/MyStaticLibrary.h"
#include "../../ThirdParty/MyLibrary/MySharedLibrary/MySharedLibrary.h"

// Sets default values
AMyPluginActor::AMyPluginActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyPluginActor::BeginPlay()
{
	Super::BeginPlay();
	this->DisplayText();
}

// Called every frame
void AMyPluginActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPluginActor::DisplayText()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Hello from MyPlugin!");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::FString(MyStaticLibrary().c_str()));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, FString::FString(MySharedLibrary().c_str()));
}

