#include "Configure.hpp"

void configurationSpecification(Configuration &config)
{
    DSC<CppSourceTarget> &fmt = config.getCppObjectDSC("fmt");
    fmt.getSourceTarget().moduleDirs("3rdParty/fmt/src").publicHUIncludes("3rdParty/fmt/include");

    DSC<CppSourceTarget> &rapidJson = config.getCppObjectDSC("rapidjson");
    rapidJson.getSourceTarget().publicHUIncludes("3rdParty/rapidjson/include");

    DSC<CppSourceTarget> &phmap = config.getCppObjectDSC("phmap");
    phmap.getSourceTarget().publicHUIncludes("3rdParty/parallel-hashmap/parallel_hashmap");

    DSC<CppSourceTarget> &hconfigure = config.getCppObjectDSC("hconfigure").publicDeps(rapidJson, phmap, fmt);
    hconfigure.getSourceTarget().moduleDirs("hconfigure/src").publicHUIncludes("hconfigure/header");
}

void buildSpecification()
{
    getConfiguration();
    CALL_CONFIGURATION_SPECIFICATION
}

MAIN_FUNCTION