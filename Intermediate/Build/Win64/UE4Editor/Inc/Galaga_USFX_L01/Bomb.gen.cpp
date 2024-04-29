// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L01/Bomb.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBomb() {}
// Cross Module References
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ABomb_NoRegister();
	GALAGA_USFX_L01_API UClass* Z_Construct_UClass_ABomb();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L01();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ABomb::StaticRegisterNativesABomb()
	{
	}
	UClass* Z_Construct_UClass_ABomb_NoRegister()
	{
		return ABomb::StaticClass();
	}
	struct Z_Construct_UClass_ABomb_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BombMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BombMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TiempoExplosion_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TiempoExplosion;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABomb_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABomb_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Bomb.h" },
		{ "ModuleRelativePath", "Bomb.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABomb_Statics::NewProp_BombMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Bomb.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABomb_Statics::NewProp_BombMesh = { "BombMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABomb, BombMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABomb_Statics::NewProp_BombMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABomb_Statics::NewProp_BombMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABomb_Statics::NewProp_TiempoExplosion_MetaData[] = {
		{ "Category", "Bomb" },
		{ "ModuleRelativePath", "Bomb.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABomb_Statics::NewProp_TiempoExplosion = { "TiempoExplosion", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABomb, TiempoExplosion), METADATA_PARAMS(Z_Construct_UClass_ABomb_Statics::NewProp_TiempoExplosion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABomb_Statics::NewProp_TiempoExplosion_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABomb_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomb_Statics::NewProp_BombMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomb_Statics::NewProp_TiempoExplosion,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABomb_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABomb>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABomb_Statics::ClassParams = {
		&ABomb::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABomb_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABomb_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABomb_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABomb_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABomb()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABomb_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABomb, 114219994);
	template<> GALAGA_USFX_L01_API UClass* StaticClass<ABomb>()
	{
		return ABomb::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABomb(Z_Construct_UClass_ABomb, &ABomb::StaticClass, TEXT("/Script/Galaga_USFX_L01"), TEXT("ABomb"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABomb);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif