// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/EstadoDebil.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstadoDebil() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstadoDebil_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AEstadoDebil();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UNaveNodrizaState_NoRegister();
// End Cross Module References
	void AEstadoDebil::StaticRegisterNativesAEstadoDebil()
	{
	}
	UClass* Z_Construct_UClass_AEstadoDebil_NoRegister()
	{
		return AEstadoDebil::StaticClass();
	}
	struct Z_Construct_UClass_AEstadoDebil_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstadoDebil_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstadoDebil_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstadoDebil.h" },
		{ "ModuleRelativePath", "EstadoDebil.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstadoDebil_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UNaveNodrizaState_NoRegister, (int32)VTABLE_OFFSET(AEstadoDebil, INaveNodrizaState), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstadoDebil_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstadoDebil>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstadoDebil_Statics::ClassParams = {
		&AEstadoDebil::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstadoDebil_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstadoDebil_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstadoDebil()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstadoDebil_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstadoDebil, 21297002);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AEstadoDebil>()
	{
		return AEstadoDebil::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstadoDebil(Z_Construct_UClass_AEstadoDebil, &AEstadoDebil::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AEstadoDebil"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstadoDebil);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
