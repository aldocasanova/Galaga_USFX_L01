// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/OmegaStragedy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaStragedy() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AOmegaStragedy_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AOmegaStragedy();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldStragedy_NoRegister();
// End Cross Module References
	void AOmegaStragedy::StaticRegisterNativesAOmegaStragedy()
	{
	}
	UClass* Z_Construct_UClass_AOmegaStragedy_NoRegister()
	{
		return AOmegaStragedy::StaticClass();
	}
	struct Z_Construct_UClass_AOmegaStragedy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOmegaStragedy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOmegaStragedy_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OmegaStragedy.h" },
		{ "ModuleRelativePath", "OmegaStragedy.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AOmegaStragedy_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFieldStragedy_NoRegister, (int32)VTABLE_OFFSET(AOmegaStragedy, IFieldStragedy), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOmegaStragedy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOmegaStragedy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AOmegaStragedy_Statics::ClassParams = {
		&AOmegaStragedy::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AOmegaStragedy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOmegaStragedy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOmegaStragedy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AOmegaStragedy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AOmegaStragedy, 296445978);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AOmegaStragedy>()
	{
		return AOmegaStragedy::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AOmegaStragedy(Z_Construct_UClass_AOmegaStragedy, &AOmegaStragedy::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AOmegaStragedy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOmegaStragedy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
