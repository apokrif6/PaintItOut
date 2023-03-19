// Paint It Out Game Demo


#include "Menu/UI/MenuUserWidget.h"
#include "PaintItOutGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UMenuUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (!StartGameButton) return;

	StartGameButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnStartGame);
}

void UMenuUserWidget::OnStartGame()
{
	const UWorld* World = GetWorld();
	if (!World) return;

	const auto PaintItOutGameInstance = World->GetGameInstance<UPaintItOutGameInstance>();
	if (!PaintItOutGameInstance) return;

	const FName StartupLevelName = PaintItOutGameInstance->GetStartupLevelName();

	if (StartupLevelName.IsNone()) return;

	UGameplayStatics::OpenLevel(this, StartupLevelName);
}
