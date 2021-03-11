// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

USTRUCT()
struct FServerData 
{
	GENERATED_BODY()

	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUserName;
};

UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()	

public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FServerData> ServerNames);

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
	UPROPERTY(meta = (BindWidget))
	class UButton* BackHostMenuButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* HostHostMenuButton;
	
	//WIDGETSWITCHERS
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;
	
	//MENUS
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;
	UPROPERTY(meta = (BindWidget))
	class UWidget* HostMenu;
	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;

	//INPUT
	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* ServerList;
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* ServerHostName;
	

	//FUNCTIONAL
	UFUNCTION()
	void HostServer();
	UFUNCTION()
	void JoinServer();
	UFUNCTION()
	void QuitPressed();

	//UI
	UFUNCTION()
	void OpenHostMenu();
	UFUNCTION()
	void OpenJoinMenu();
	UFUNCTION()
	void OpenMainMenu();

	TOptional<uint32> SelectedIndex;

	void UpdateChildren();
};
