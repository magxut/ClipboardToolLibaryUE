#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ClipboardTools.generated.h"

UENUM(BlueprintType)
enum class EClipboardFormat : uint8
{
	TEXT UMETA(DisplayName = "CF_TEXT"),
	UNICODETEXT UMETA(DisplayName = "CF_UNICODETEXT"),
	Empty UMETA(DisplayName = "Empty"),
	ContainsSubstring UMETA(DisplayName = "Clipboard Type")
};

UCLASS()
class CLIPBOARDTOOLS_API UClipboardToolsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Clipboard")
	static FString GetClipboardContent();
	
	UFUNCTION(BlueprintPure, Category = "Clipboard", meta = (DisplayName = "Is Clipboard Empty"))
	static bool IsClipboardEmpty();

	UFUNCTION(BlueprintCallable, Category = "Clipboard")
	static bool SetClipboardContent(const FString& Content);

	UFUNCTION(BlueprintCallable, Category = "Clipboard")
	static bool DoesClipboardContentContain(const FString& Substring);

	UFUNCTION(BlueprintCallable, Category = "Clipboard")
	static bool ClearClipboard();

	UFUNCTION(BlueprintCallable, Category = "Clipboard")
	static EClipboardFormat GetClipboardFormat();

};

class FClipboardToolsModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};