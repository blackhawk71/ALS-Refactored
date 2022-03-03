#pragma once

#include "AlsCharacter.h"
#include "AlsCharacterExample.generated.h"

class UAlsCameraComponent;

UCLASS(AutoExpandCategories = ("Settings|Als Character Example", "State|Als Character Example"))
class ALSEXAMPLE_API AAlsCharacterExample : public AAlsCharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Meta = (AllowPrivateAccess))
	TObjectPtr<UAlsCameraComponent> AlsCamera;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings|Als Character Example",
		Meta = (AllowPrivateAccess, ClampMin = 0, ForceUnits = "x"))
	float LookUpMouseSensitivity{2.5f};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings|Als Character Example",
		Meta = (AllowPrivateAccess, ClampMin = 0, ForceUnits = "x"))
	float LookRightMouseSensitivity{2.5f};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings|Als Character Example",
		Meta = (AllowPrivateAccess, ClampMin = 0, ForceUnits = "deg/s"))
	float LookUpRate{90.0f};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings|Als Character Example",
		Meta = (AllowPrivateAccess, ClampMin = 0, ForceUnits = "deg/s"))
	float LookRightRate{240.0f};

private:
	FTimerHandle SprintStartTimer;

public:
	AAlsCharacterExample();

	virtual void PossessedBy(AController* NewController) override;

	// Camera

protected:
	virtual void CalcCamera(float DeltaTime, FMinimalViewInfo& ViewInfo) override;

	// Input

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void InputLookUpMouse(float Value);

	void InputLookRightMouse(float Value);

	void InputLookUp(float Value);

	void InputLookRight(float Value);

	void InputMoveForward(float Value);

	void InputMoveRight(float Value);

	void InputSprintPressed();

	void InputSprintReleased();

	void InputRoll();

	void InputWalk();

	void InputCrouch();

	void InputJumpPressed();

	void InputJumpReleased();

	void InputAimPressed();

	void InputAimReleased();

	void InputRotationModePressed();

	void InputRagdollPressed();

	void InputViewModePressed();

	void InputSwitchShoulderPressed();

	// Debug

public:
	virtual void DisplayDebug(UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& Unused, float& VerticalPosition) override;
};
