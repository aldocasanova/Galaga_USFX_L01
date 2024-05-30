// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/FieldStragedy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFieldStragedy() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldStragedy_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_UFieldStragedy();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
// End Cross Module References
	void UFieldStragedy::StaticRegisterNativesUFieldStragedy()
	{
	}
	UClass* Z_Construct_UClass_UFieldStragedy_NoRegister()
	{
		return UFieldStragedy::StaticClass();
	}
	struct Z_Construct_UClass_UFieldStragedy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFieldStragedy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFieldStragedy_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "FieldStragedy.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFieldStragedy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IFieldStragedy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFieldStragedy_Statics::ClassParams = {
		&UFieldStragedy::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UFieldStragedy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFieldStragedy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFieldStragedy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFieldStragedy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFieldStragedy, 2179446483);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<UFieldStragedy>()
	{
		return UFieldStragedy::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFieldStragedy(Z_Construct_UClass_UFieldStragedy, &UFieldStragedy::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("UFieldStragedy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFieldStragedy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
