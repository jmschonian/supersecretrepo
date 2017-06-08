#pragma once

//Windows
#include <WinSDKVer.h>
#define _WIN32_WINNT 0x0600
#include <SDKDDKVer.h>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

//STL
#include <vector>

//STDLIB
#include <algorithm>
#include <iostream>
#include <fstream>

//Common
#include "../Core/SimpleMath.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;