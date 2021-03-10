// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()	

public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FString> ServerNames);

	void SelectIndex(uint32 Index);

protected:
	virtual bool Initialize();

private:
	TSubclassOf<UUserWidget> ServerRowClass;

	//BUTTONS
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* GameQuitButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* BackJoinMenuButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinJoinMenuButton;
	
	//WIDGETSWITCHERS
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;
	
	//MENUS
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;
	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	//INPUT
	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* ServerList;

	//FUNCTIONAL
	UFUNCTION()
	void HostServer();
	UFUNCTION()
	void JoinServer();
	UFUNCTION()
	void QuitPressed();

	//UI
	UFUNCTION()
	void OpenJoinMenu();
	UFUNCTION()
	void OpenMainMenu();

	TOptional<uint32> SelectedIndex;

	void UpdateChildren();
};
