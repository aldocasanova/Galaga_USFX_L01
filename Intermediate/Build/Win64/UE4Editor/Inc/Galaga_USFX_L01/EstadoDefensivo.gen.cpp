// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/EstadoDefensivo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstadoDefensivo() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstadoDefensivo_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstadoDefensivo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UNaveNodrizaState_NoRegister();
// End Cross Module References
	void AEstadoDefensivo::StaticRegisterNativesAEstadoDefensivo()
	{
	}
	UClass* Z_Construct_UClass_AEstadoDefensivo_NoRegister()
	{
		return AEstadoDefensivo::StaticClass();
	}
	struct Z_Construct_UClass_AEstadoDefensivo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstadoDefensivo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstadoDefensivo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstadoDefensivo.h" },
		{ "ModuleRelativePath", "EstadoDefensivo.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstadoDefensivo_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UNaveNodrizaState_NoRegister, (int32)VTABLE_OFFSET(AEstadoDefensivo, INaveNodrizaState), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstadoDefensivo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstadoDefensivo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstadoDefensivo_Statics::ClassParams = {
		&AEstadoDefensivo::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstadoDefensivo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstadoDefensivo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstadoDefensivo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstadoDefensivo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstadoDefensivo, 275617062);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AEstadoDefensivo>()
	{
		return AEstadoDefensivo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstadoDefensivo(Z_Construct_UClass_AEstadoDefensivo, &AEstadoDefensivo::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AEstadoDefensivo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstadoDefensivo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
