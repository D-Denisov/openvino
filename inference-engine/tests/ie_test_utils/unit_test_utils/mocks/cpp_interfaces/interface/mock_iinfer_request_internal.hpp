// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <gmock/gmock.h>

#include <map>
#include <string>
#include <vector>

#include <cpp_interfaces/impl/ie_infer_request_internal.hpp>
#include <cpp_interfaces/impl/ie_variable_state_internal.hpp>

class MockIInferRequestInternal : public InferenceEngine::IInferRequestInternal {
public:
    MOCK_METHOD0(Infer, void());
    MOCK_CONST_METHOD1(GetPerformanceCounts, void(std::map<std::string, InferenceEngine::InferenceEngineProfileInfo> &));
    MOCK_METHOD2(SetBlob, void(const char *name, const InferenceEngine::Blob::Ptr &));
    MOCK_METHOD2(GetBlob, void(const char *name, InferenceEngine::Blob::Ptr &));
    MOCK_METHOD3(SetBlob, void(const char*, const InferenceEngine::Blob::Ptr&, const InferenceEngine::PreProcessInfo&));
    MOCK_METHOD2(GetPreProcess, void(const char*, const InferenceEngine::PreProcessInfo**));
    MOCK_METHOD0(QueryState, std::vector<InferenceEngine::IVariableStateInternal::Ptr>());
};
