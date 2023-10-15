// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Cpp_blueprintLibs.generated.h"

/**
 * 
 */
UCLASS()
class TTT_API UCpp_blueprintLibs : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "File Utility")
	static FString OpenFileDialog();

	UFUNCTION(BlueprintCallable, Category= "dggdggdag")
	void call();


	UFUNCTION(BlueprintCallable, Category = "File Access")
	static bool GetFilePath(FString& OutFilePath);

	UFUNCTION(BlueprintCallable, Category = "File Access")
	static bool ReadFile(const FString& FilePath, FString& FileContents);
};
