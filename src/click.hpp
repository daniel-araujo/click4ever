#pragma once

enum class ClickOnLeaveArea {
  Exit,
  Pause,
};

int click(
  int button,
  uint64_t delay,
  uint64_t position_check_time,
  int movement_treshold,
  ClickOnLeaveArea click_on_leave_area
);
