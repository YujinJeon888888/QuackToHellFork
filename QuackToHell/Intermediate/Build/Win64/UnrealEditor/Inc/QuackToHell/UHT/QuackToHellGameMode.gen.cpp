// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuackToHell/QuackToHellGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuackToHellGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
QUACKTOHELL_API UClass* Z_Construct_UClass_AQuackToHellGameMode();
QUACKTOHELL_API UClass* Z_Construct_UClass_AQuackToHellGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_QuackToHell();
// End Cross Module References

// Begin Class AQuackToHellGameMode
void AQuackToHellGameMode::StaticRegisterNativesAQuackToHellGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AQuackToHellGameMode);
UClass* Z_Construct_UClass_AQuackToHellGameMode_NoRegister()
{
	return AQuackToHellGameMode::StaticClass();
}
struct Z_Construct_UClass_AQuackToHellGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "QuackToHellGameMode.h" },
		{ "ModuleRelativePath", "QuackToHellGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AQuackToHellGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AQuackToHellGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_QuackToHell,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AQuackToHellGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AQuackToHellGameMode_Statics::ClassParams = {
	&AQuackToHellGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AQuackToHellGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AQuackToHellGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AQuackToHellGameMode()
{
	if (!Z_Registration_Info_UClass_AQuackToHellGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AQuackToHellGameMode.OuterSingleton, Z_Construct_UClass_AQuackToHellGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AQuackToHellGameMode.OuterSingleton;
}
template<> QUACKTOHELL_API UClass* StaticClass<AQuackToHellGameMode>()
{
	return AQuackToHellGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AQuackToHellGameMode);
AQuackToHellGameMode::~AQuackToHellGameMode() {}
// End Class AQuackToHellGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_swu_Documents_Unreal_Projects_QuackToHellFork_QuackToHell_Source_QuackToHell_QuackToHellGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AQuackToHellGameMode, AQuackToHellGameMode::StaticClass, TEXT("AQuackToHellGameMode"), &Z_Registration_Info_UClass_AQuackToHellGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AQuackToHellGameMode), 197999214U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_swu_Documents_Unreal_Projects_QuackToHellFork_QuackToHell_Source_QuackToHell_QuackToHellGameMode_h_1950991830(TEXT("/Script/QuackToHell"),
	Z_CompiledInDeferFile_FID_Users_swu_Documents_Unreal_Projects_QuackToHellFork_QuackToHell_Source_QuackToHell_QuackToHellGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_swu_Documents_Unreal_Projects_QuackToHellFork_QuackToHell_Source_QuackToHell_QuackToHellGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
