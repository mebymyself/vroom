#ifndef STEP_H
#define STEP_H

/*

This file is part of VROOM.

Copyright (c) 2015-2022, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include <string>

#include "structures/vroom/break.h"
#include "structures/vroom/job.h"
#include "structures/vroom/location.h"
#include "structures/vroom/solution/violations.h"

namespace vroom {

struct Step {
  const STEP_TYPE step_type;
  const std::optional<JOB_TYPE> job_type;
  const std::optional<Location> location;
  const Id id;
  UserDuration setup;
  UserDuration service;
  const Amount load;
  const std::string description;

  UserDuration arrival;
  UserDuration duration;
  UserDuration waiting_time;
  Distance distance;

  Violations violations;

  Step(STEP_TYPE type, Location location, Amount load);

  Step(const Job& job, const UserDuration setup, Amount load);

  Step(const Break& b, Amount load);

  UserDuration departure() const;
};

} // namespace vroom

#endif
