-- premake5.lua
workspace "RTweekend"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "RTweekend"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/WalnutExternal.lua"

include "RTweekend"
