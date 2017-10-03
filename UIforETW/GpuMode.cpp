/*
Copyright 2015 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "stdafx.h"

#include <string>
#include "GpuMode.h"

// settings from C:\Program Files (x86)\Windows Kits\10\Windows Performance Toolkit\gpuview\log.cmd
const wchar_t* TRACE_DXVA2 = L"+a0386e75-f70c-464c-a9ce-33c44e091623:0xffff:5";
const wchar_t* TRACE_MMCSS = L"+f8f10121-b617-4a56-868b-9df1b27fe32c:0xffff:5";
const wchar_t* TRACE_WMDRM = L"+6e03dd26-581b-4ec5-8f22-601a4de5f022:0xffff:5";
const wchar_t* TRACE_WME = L"+8f2048e0-f260-4f57-a8d1-932376291682";
const wchar_t* TRACE_WMP = L"+681069c4-b785-466a-bc63-4aa616644b68:0xffff:5";
const wchar_t* TRACE_DVD = L"+75d4a1bb-7cc6-44b1-906d-d5e05be6d060:0xffff:5";
const wchar_t* TRACE_DSHOW = L"+28cf047a-2437-4b24-b653-b9446a419a69";
const wchar_t* TRACE_MF = L"+f404b94e-27e0-4384-bfe8-1d8d390b0aa3+362007f7-6e50-4044-9082-dfa078c63a73:0x000000000000ffff:0x5";
const wchar_t* TRACE_AE = L"+a6a00efd-21f2-4a99-807e-9b3bf1d90285:0x000000000000ffff:0x5";
const wchar_t* TRACE_HME = L"+63770680-05F1-47E0-928A-9ACFDCF52147:0xffff:5";
const wchar_t* TRACE_HDDVD = L"+779d8cdc-666b-4bf4-a367-9df89d6901e8:0xffff:5";
const wchar_t* TRACE_DWMAPIGUID = L"+71dd85bc-d474-4974-b0f6-93ffc5bfbd04::6";
const wchar_t* TRACE_SCHEDULEGUID = L"+8cc44e31-7f28-4f45-9938-4810ff517464:0xffff:6";
const wchar_t* TRACE_DX = L"+DX";
const wchar_t* TRACE_WARP = L"+ee685ec4-8270-4b08-9e4e-8b356f48f92f:0";
const wchar_t* TRACE_DXGI = L"+CA11C036-0102-4A2D-A6AD-F03CFED5D3C9:0xf:6:'stack'";
const wchar_t* TRACE_D3D12 = L"+5d8087dd-3a9b-4f56-90df-49196cdc4f11:0xffffffffffffffff:6:'stack'";
const wchar_t* TRACE_D3D11 = L"+db6f6ddb-ac77-4e88-8253-819df9bbf140:0xffffffffffffffff:6:'stack'";
const wchar_t* TRACE_D3D10LEVEL9 = L"+7E7D3382-023C-43cb-95D2-6F0CA6D70381:0x1";
const wchar_t* TRACE_DXC = L"+802ec45a-1e99-4b83-9920-87c98277ba9d";
const wchar_t* TRACE_DXC_ALL = L"+802ec45a-1e99-4b83-9920-87c98277ba9d:0x10FFFF:5:'stack'";
const wchar_t* TRACE_DXC_LONGHAUL = L"+802ec45a-1e99-4b83-9920-87c98277ba9d:0x800:5";
const wchar_t* TRACE_DXC_MIN = L"+802ec45a-1e99-4b83-9920-87c98277ba9d:0x800:5";
const wchar_t* TRACE_DXC_LIGHT = L"+802ec45a-1e99-4b83-9920-87c98277ba9d:0x826:5";
const wchar_t* TRACE_DXC_NORMAL = L"+802ec45a-1e99-4b83-9920-87c98277ba9d:0x100236:5";
const wchar_t* TRACE_DXC_STACKS = L"+802ec45a-1e99-4b83-9920-87c98277ba9d:0x208041:5:'stack'";
const wchar_t* TRACE_UMD = L"+a688ee40-d8d9-4736-b6f9-6b74935ba3b1:0xffff:5";
const wchar_t* TRACE_DWM = L"+a42c77db-874f-422e-9b44-6d89fe2bd3e5:0x000000007fffffff:0x5";
const wchar_t* TRACE_DWM2 = L"+8c9dd1ad-e6e5-4b07-b455-684a9d879900:0xFFFF:6";
const wchar_t* TRACE_DWM3 = L"+9e9bba3c-2e38-40cb-99f4-9e8281425164:0xFFFF:6";
const wchar_t* TRACE_CODEC = L"+ea6d6e3b-7014-4ab1-85db-4a50cda32a82:0xffff:5";
const wchar_t* TRACE_KMFD = L"+E7C7EDF9-D0E4-4338-8AE3-BCA3C5B4B4A3";
const wchar_t* TRACE_UMFD = L"+a70bc228-e778-4061-86fa-debb03fda64a";
const wchar_t* TRACE_TESTFRAMEWORK = L"+31293f4f-f7bb-487d-8b3b-f537b827352f";
const wchar_t* TRACE_TEST = L"+42C4E0C1-0D92-46f0-842C-1E791FA78D52";
const wchar_t* TRACE_SC = L"+30336ed4-e327-447c-9de0-51b652c86108";
const wchar_t* TRACE_XAML = L"+531A35AB-63CE-4BCF-AA98-F88C7A89E455:0xffff";
const wchar_t* TRACE_WIN32K = L"+8c416c79-d49b-4f01-a467-e56d3aa8234c:0xffff";
const wchar_t* TRACE_D2D = L"+dcb453db-c652-48be-a0f8-a64459d5162e:0:5";
const wchar_t* TRACE_D2DSCENARIOS = L"+712909c0-6e57-4121-b639-87c8bf9004e0";
const wchar_t* TRACE_D3D9_PRESENT = L"+783ACA0A-790E-4d7f-8451-AA850511C6B9:0xf:6";
const wchar_t* TRACE_DXGI_PRESENT = L"+CA11C036-0102-4A2D-A6AD-F03CFED5D3C9:0xf:6";
const wchar_t* TRACE_D3D11_PRESENT = L"+db6f6ddb-ac77-4e88-8253-819df9bbf140:0xffffffffffffffff:6";
const wchar_t* TRACE_DXC_ALL_PRESENT = L"+802ec45a-1e99-4b83-9920-87c98277ba9d:0x10FFFF:5";
const wchar_t* TRACE_DXC_PRESENT = L"+802ec45a-1e99-4b83-9920-87c98277ba9d:0x208041:5";
// setting from https://developer.valvesoftware.com/wiki/SteamVR/Installing_GPUView
const wchar_t* TRACE_VR = L"+8c8f13b1-60eb-4b6a-a433-de86104115ac";

static std::wstring TraceCSProvidersMin()
{
    std::wstring providers;
    providers += TRACE_UMD;
    providers += TRACE_DXGI;
    providers += TRACE_D3D12;
    providers += TRACE_D3D11;
    providers += TRACE_D3D10LEVEL9;
    return providers;
}

static std::wstring TraceCSProvidersPresent()
{
    std::wstring providers;
    providers += TRACE_UMD;
    providers += TRACE_DXGI_PRESENT;
    providers += TRACE_D3D11_PRESENT;
    providers += TRACE_D3D9_PRESENT;
    return providers;
}

static std::wstring TraceCSProvidersLight()
{
    return TraceCSProvidersMin();
}

static std::wstring TraceCSProvidersNormal()
{
    return TraceCSProvidersLight();
}

static std::wstring TraceCSProvidersVerbose()
{
    return TraceCSProvidersNormal();
}

static std::wstring TraceCSStateMin()
{
    std::wstring providers;
    providers += TRACE_UMD;
    providers += TRACE_DXGI;
    providers += TRACE_D3D12;
    providers += TRACE_D3D11;
    providers += TRACE_D3D10LEVEL9;
    return providers;
}

static std::wstring TraceCSStatePresent()
{
    std::wstring providers;
    providers += TRACE_UMD;
    providers += TRACE_DXGI_PRESENT;
    providers += TRACE_D3D11_PRESENT;
    providers += TRACE_D3D9_PRESENT;
    return providers;
}

static std::wstring TraceCSStateLight()
{
    return TraceCSStateMin();
}

static std::wstring TraceCSStateNormal()
{
    return TraceCSStateLight();
}

static std::wstring TraceCSStateVerbose()
{
    return TraceCSStateNormal();
}

static std::wstring TraceNoCSProvidersMin()
{
    std::wstring providers;
    providers += TRACE_DXC_STACKS;
    return providers;
}

static std::wstring TraceNoCSProvidersPresent()
{
    std::wstring providers;
    providers += TRACE_DXC_PRESENT;
    providers += TRACE_DWM3;
    providers += TRACE_WIN32K;
    return providers;
}

static std::wstring TraceNoCSProvidersLight()
{
    std::wstring providers;
    providers += TraceNoCSProvidersMin();
    providers += TRACE_MF;
    providers += TRACE_WME;
    return providers;
}

static std::wstring TraceNoCSProvidersNormal()
{
    std::wstring providers;
    providers += TraceNoCSProvidersLight();
    providers += TRACE_SCHEDULEGUID;
    providers += TRACE_SC;
    providers += TRACE_WIN32K;
    providers += TRACE_DWM;
    providers += TRACE_DWM2;
    providers += TRACE_DWM3;
    providers += TRACE_TESTFRAMEWORK;
    providers += TRACE_TEST;
    providers += TRACE_DSHOW;
    providers += TRACE_AE;
    providers += TRACE_DXVA2;
    return providers;
}

static std::wstring TraceNoCSProvidersVerbose()
{
    std::wstring providers;
    providers += TraceNoCSProvidersNormal();
    providers += TRACE_D2DSCENARIOS;
    providers += TRACE_D2D;
    providers += TRACE_MMCSS;
    providers += TRACE_WMDRM;
    providers += TRACE_WMP;
    providers += TRACE_DVD;
    providers += TRACE_HME;
    providers += TRACE_HDDVD;
    providers += TRACE_DWMAPIGUID;
    providers += TRACE_CODEC;
    return providers;
}

static std::wstring TraceCSProvidersDefault()
{
    std::wstring providers;

    // Apparently we need a different provider for graphics profiling
    // on Windows 8 and above.
    if ( IsWindows8OrGreater() )
    {
        // This provider is needed for GPU profiling on Windows 8+
        providers += L"+Microsoft-Windows-DxgKrnl:0xFFFF:5";
        if ( !IsWindowsServer() )
        {
            // Present events on Windows 8 + -- non-server SKUs only.
            providers += L"+Microsoft-Windows-MediaEngine";
        }
    }
    else
    {
        // Necessary providers for a minimal GPU profiling setup.
        // DirectX logger:
        providers += L"+DX:0x2F";
    }
    return providers;
}

GPUProviders GetGpuProviders( GPUMode gpuMode )
{
    GPUProviders providers;

    switch ( gpuMode )
    {
        case kGPUDefault:
            providers.csProviders = TraceCSProvidersDefault();
            break;
        case kGPUNormal:
            providers.csProviders = TRACE_DXC_NORMAL + TraceCSProvidersNormal();
            providers.csState = TRACE_DXC_ALL + TraceCSStateNormal();
            providers.noCsProviers = std::wstring( TRACE_DX ) + L":0x2F" + TRACE_XAML + L":4" + TRACE_WARP + L":1" + TraceNoCSProvidersNormal();
            break;
        case kGPULight:
            providers.csProviders = TRACE_DXC_LIGHT + TraceCSProvidersLight();
            providers.csState = TRACE_DXC_ALL + TraceCSStateLight();
            providers.noCsProviers = std::wstring( TRACE_DX ) + L":0x2F" + TRACE_XAML + L":4" + TRACE_WARP + L":1" + TraceNoCSProvidersLight();
            break;
        case kGPULonghaul:
            providers.csProviders = TRACE_DXC_LONGHAUL;
            break;
        case kGPUPresent:
            providers.csProviders = TRACE_DXC_MIN + TraceCSProvidersPresent();
            providers.csState = TRACE_DXC_ALL_PRESENT + TraceCSStatePresent();
            providers.noCsProviers = std::wstring( TRACE_DX ) + L":0x9" + TRACE_XAML + L":4" + TraceNoCSProvidersPresent();
            break;
        case kGPUMin:
            providers.csProviders = TRACE_DXC_MIN + TraceCSProvidersMin();
            providers.csState = TRACE_DXC_ALL + TraceCSStateMin();
            providers.noCsProviers = std::wstring(TRACE_DX) + L":0x9" + TRACE_XAML + L":4" + TRACE_WARP + L":1" + TraceNoCSProvidersMin();
            break;
        case kGPUVerbose:
            providers.csProviders = TRACE_DXC_NORMAL + TraceCSProvidersVerbose();
            providers.csState = TRACE_DXC_ALL + TraceCSStateVerbose();
            providers.noCsProviers = std::wstring(TRACE_DX) + TRACE_XAML + L":5" + TRACE_WARP + L":0x12" + TraceNoCSProvidersVerbose();
            break;
    }

    return providers;
}
