﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_blueprintLibs.h"

#include "Windows.h"

FString UCpp_blueprintLibs::OpenFileDialog()
{

	FString FilePath;
	// Use platform-specific code to open the file dialog and retrieve the selected file path
	// For Windows, you can use the Windows API or platform-specific libraries.
	// Windows File Dialog Example:
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = TEXT("All Files (*.*)\0*.*\0");
	ofn.lpstrFile = FilePath.GetCharArray().GetData();
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn))
	{
		return FilePath;
	}
	return FString();
}

void UCpp_blueprintLibs::call()
{
}

bool UCpp_blueprintLibs::GetFilePath(FString& OutFilePath)
{

	TCHAR Buffer[MAX_PATH];
	if (GetModuleFileName(nullptr, Buffer, MAX_PATH) > 0)
	{
		OutFilePath = Buffer;
		return true;
	}
	return false;
}

bool UCpp_blueprintLibs::ReadFile(const FString& FilePath, FString& FileContents)
{

	FileContents.Empty();
	if (FFileHelper::LoadFileToString(FileContents, *FilePath))
	{
		return true;
	}
	return false;
	
}
