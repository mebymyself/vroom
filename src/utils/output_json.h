#ifndef OUTPUT_JSON_H
#define OUTPUT_JSON_H

/*

This file is part of VROOM.

Copyright (c) 2015-2022, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "../include/rapidjson/include/rapidjson/document.h"
#include "structures/vroom/solution/solution.h"

namespace vroom::io {

rapidjson::Document to_json(const Solution& sol, bool geometry);

rapidjson::Value to_json(const Summary& summary,
                         bool geometry,
                         rapidjson::Document::AllocatorType& allocator);

rapidjson::Value to_json(const ComputingTimes& ct,
                         bool geometry,
                         rapidjson::Document::AllocatorType& allocator);

rapidjson::Value to_json(const Route& route,
                         bool geometry,
                         rapidjson::Document::AllocatorType& allocator);

rapidjson::Value to_json(const Step& s,
                         bool geometry,
                         rapidjson::Document::AllocatorType& allocator);

rapidjson::Value to_json(const Location& loc,
                         rapidjson::Document::AllocatorType& allocator);

void write_to_json(const Solution& sol,
                   const std::string& output_file = "",
                   bool geometry = false);

} // namespace vroom::io

#endif
