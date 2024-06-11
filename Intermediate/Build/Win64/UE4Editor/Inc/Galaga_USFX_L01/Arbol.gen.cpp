// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/Arbol.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeArbol() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AArbol_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_AArbol();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldElement_NoRegister();
// End Cross Module References
	void AArbol::StaticRegisterNativesAArbol()
	{
	}
	UClass* Z_Construct_UClass_AArbol_NoRegister()
	{
		return AArbol::StaticClass();
	}
	struct Z_Construct_UClass_AArbol_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AArbol_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArbol_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Arbol.h" },
		{ "ModuleRelativePath", "Arbol.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AArbol_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UFieldElement_NoRegister, (int32)VTABLE_OFFSET(AArbol, IFieldElement), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AArbol_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AArbol>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AArbol_Statics::ClassParams = {
		&AArbol::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AArbol_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AArbol_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AArbol()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AArbol_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AArbol, 1953736082);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<AArbol>()
	{
		return AArbol::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AArbol(Z_Construct_UClass_AArbol, &AArbol::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("AArbol"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AArbol);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
