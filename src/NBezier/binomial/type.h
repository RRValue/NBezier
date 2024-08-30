#pragma once

#include "NBezier/defines.h"

#include <concepts>

OpenNameSpace(NBezier);
OpenNameSpace(Binomial);

template<class T>
concept Type = (std::integral<T> || std::floating_point<T>)&&  //
    !std::is_same<T, bool>::value;

CloseNameSpace(Binomial);
CloseNameSpace(NBezier);