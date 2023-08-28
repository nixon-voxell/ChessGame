#include "HideUnhideButtons.h"
#include "Components/Button.h"
#include "Components/SceneComponent.h"

void UHideUnhideButtons::SelectAllButtonsCustom()
{
    // Prepare a list to hold all child widgets.
    TArray<UWidget*> Children;

    // For each widget in the list...
    for (UWidget* Widget : Children)
    {
        // Check if the widget is a button.
        UButton* Button = Cast<UButton>(Widget);
        if (Button)
        {
            // Toggle the button's visibility (show/hide).
            Button->SetVisibility(Button->IsVisible() ? ESlateVisibility::Hidden : ESlateVisibility::Visible);
        }
    }
}