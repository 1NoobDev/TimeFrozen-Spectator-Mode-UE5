# Custom Spectator Pawn with Time Dilation

The Custom Spectator Pawn is an Unreal Engine feature that allows players to toggle between their character and a spectator mode, providing a unique perspective of the game world. In spectator mode, players can adjust the time dilation to experience the game at different speeds.

## Features

- **Toggle Spectator Mode**: Players can switch between their normal character and a spectator pawn that can fly around the game world.
- **Time Dilation Adjustment**: While in spectator mode, players can adjust the time dilation using the mouse wheel, allowing for a slower or faster perception of time within the game.

## Usage Instructions

1. **Toggling Spectator Mode**: Press the designated key (default is not set, you must bind it in your project's input settings) to switch between your player character and the spectator pawn.
2. **Adjusting Time Dilation**: Use the mouse wheel to increase or decrease the time dilation. Scrolling up will speed up the game time, while scrolling down will slow it down.

## Configuration

- **Global Time Dilation**: Can be set in the editor under the `PlayerSpectatorSwitchComponent` properties. This value determines the overall speed of the game world when in spectator mode.
- **Custom Time Dilation**: Also set in the editor under the `PlayerSpectatorSwitchComponent` properties. This value affects the spectator pawn's perception of time and can be dynamically adjusted with the mouse wheel during gameplay.

## Integration

To integrate the Custom Spectator Pawn into your Unreal Engine project, ensure the following components and settings are configured:

### PlayerSpectatorSwitchComponent

- Attach this component to the player character to enable the ability to toggle spectator mode.
- Bind an input action named `ToggleSpectatorMode` to allow players to switch modes at runtime.

### CustomSpectatorPawn

- Inherits from `ASpectatorPawn`, providing basic spectator functionality with additional time dilation control.
- Ensure the `MouseWheelAxis` is bound in your project's input settings to allow for time dilation adjustments.

### MinTimeDilation and MaxTimeDilation

- These static constants define the range for time dilation adjustments. Set these values according to the desired effect in your game.

### AdjustCustomTimeDilation Function

- This function is responsible for changing the `CustomSpectatorTimeDilationValue` based on mouse wheel input. It ensures the value stays within the defined range.

## Notes

- The `CustomTimeDilation` property of the spectator pawn is directly affected by the `CustomSpectatorTimeDilationValue` from the `PlayerSpectatorSwitchComponent`.
- Logging functionality is included to output the current time dilation value to the console for debugging purposes.
