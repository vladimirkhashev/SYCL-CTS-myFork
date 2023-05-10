/*******************************************************************************
//
//  SYCL 2020 Conformance Test Suite
//
//  Copyright (c) 2023 The Khronos Group Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
*******************************************************************************/

#include "../common/disabled_for_test_case.h"
#include "atomic_ref_stress_common.h"
#include <catch2/catch_test_macros.hpp>

namespace atomic_ref_stress_test_core {

// FIXME: re-enable for computecpp when
// sycl::access::address_space::generic_space and possibility of a SYCL kernel
// with an unnamed type are implemented in computecpp, re-enable for hipsycl
// when sycl::info::device::atomic_memory_order_capabilities and
// sycl::info::device::atomic_memory_scope_capabilities are implemented in
// hipsycl
DISABLED_FOR_TEST_CASE(ComputeCpp, hipSYCL)
("sycl::atomic_ref atomicity for device scope. core types",
 "[atomic_ref_stress]")({
  const auto type_pack = named_type_pack<int, float>::generate("int", "float");
  for_all_types<atomic_ref_stress_test::run_atomicity_device_scope>(type_pack);
});

DISABLED_FOR_TEST_CASE(ComputeCpp, hipSYCL)
("sycl::atomic_ref atomicity for work_group scope. core types",
 "[atomic_ref_stress]")({
  const auto type_pack = named_type_pack<int, float>::generate("int", "float");
  for_all_types<atomic_ref_stress_test::run_atomicity_work_group_scope>(
      type_pack);
});

DISABLED_FOR_TEST_CASE(ComputeCpp, hipSYCL)
("sycl::atomic_ref aquire and release. core types", "[atomic_ref_stress]")({
  const auto type_pack = named_type_pack<int, float>::generate("int", "float");
  for_all_types<atomic_ref_stress_test::run_aquire_release>(type_pack);
});

DISABLED_FOR_TEST_CASE(ComputeCpp, hipSYCL)
("sycl::atomic_ref ordering. core types", "[atomic_ref_stress]")({
  const auto type_pack = named_type_pack<int, float>::generate("int", "float");
  for_all_types<atomic_ref_stress_test::run_ordering>(type_pack);
});

}  // namespace atomic_ref_stress_test_core
