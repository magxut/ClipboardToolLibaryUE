#include "ClipboardTools.h"
#include "Windows/WindowsPlatformApplicationMisc.h"

#define LOCTEXT_NAMESPACE "FClipboardToolsModule"

void FClipboardToolsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FClipboardToolsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FString UClipboardToolsLibrary::GetClipboardContent()
{
	FString ClipboardContent;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);
	return ClipboardContent;
}

bool UClipboardToolsLibrary::IsClipboardEmpty()
{
	FString ClipboardContent;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);
	return !ClipboardContent.IsEmpty();
}

bool UClipboardToolsLibrary::SetClipboardContent(const FString& Content)
{
	FPlatformApplicationMisc::ClipboardCopy(*Content);
	FString ClipboardContent;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);
	return ClipboardContent == Content;
}

bool UClipboardToolsLibrary::DoesClipboardContentContain(const FString& Substring)
{
	FString ClipboardContent;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);
	return ClipboardContent.Contains(Substring);
}

bool UClipboardToolsLibrary::ClearClipboard()
{
	FPlatformApplicationMisc::ClipboardCopy(TEXT(""));
	FString ClipboardContent;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);
	return ClipboardContent.IsEmpty();
}

EClipboardFormat UClipboardToolsLibrary::GetClipboardFormat()
{
	FString ClipboardContent;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);

	if (ClipboardContent.IsEmpty())
	{
		return EClipboardFormat::Empty;
	}
	else if (ClipboardContent.Contains(TEXT("\0"), ESearchCase::IgnoreCase, ESearchDir::FromStart))
	{
		return EClipboardFormat::UNICODETEXT;
	}
	else
	{
		return EClipboardFormat::TEXT;
	}
}


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FClipboardToolsModule, ClipboardTools)
