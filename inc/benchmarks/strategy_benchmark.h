#pragma once

#include "strategy/strategy.h"

namespace StrategyBenchmark
{
    int64_t add(Strategy* strategy, int n_loops);
    int64_t contains(Strategy* strategy, int n_loops);
    int64_t remove(Strategy* strategy, int n_loops);
};