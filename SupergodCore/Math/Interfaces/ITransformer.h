#pragma once
#include "Common/CommonDefines.h"

namespace SupergodCore { namespace Math
{
	/// <summary>
	/// An interface for things that can transform vectors and be combined.
	/// </summary>
	template<class TTransformer, class TVector>
	interface SUPERGOD_API ITransformer
	{
		virtual TVector TransformVector(const TVector& vector) const = 0;
		virtual TTransformer CombineTransformations(const TTransformer& other) const = 0;
		virtual TTransformer DiscombineTransformations(const TTransformer& other) const = 0;
	};

	/// <summary>
	/// A namespace with static functions that call things from the ITransformer3D interface.
	/// </summary>
	namespace Transformer
	{
		/// <summary>
		/// Transforms vector by the transformer.
		/// </summary>
		/// <param name="vector">The vector to transform.</param>
		/// <param name="transformer">The transformer to transform vector by.</param>
		/// <returns>The transformed vector.</returns>
		template<class TTransformer, class TVector>
		inline TVector TransformVector(const TVector& vector, const ITransformer<TTransformer, TVector>& transformer)
		{
			return transformer.TransformVector(vector);
		}

		/// <summary>
		/// Transforms vector by the transformer.
		/// </summary>
		/// <param name="transformer">The transformer to transform vector by.</param>
		/// <param name="vector">The vector to transform.</param>
		/// <returns>The transformed vector.</returns>
		template<class TTransformer, class TVector>
		inline TVector TransformVector(const ITransformer<TTransformer, TVector>& transformer, const TVector& vector)
		{
			return TransformVector(vector, transformer);
		}

		/// <summary>
		/// Combines original with transformer.
		/// </summary>
		/// <param name="original">The first transform.</param>
		/// <param name="transformer">The transform to combine original with.</param>
		/// <returns>A combination of original and transformer.</returns>
		template<class TTransformer, class TVector>
		inline TTransformer CombineTransformations(const ITransformer<TTransformer, TVector>& original, const TTransformer& transformer)
		{
			return original.CombineTransformations(transformer);
		}

		/// <summary>
		/// Returns the transformation that when combined with secondTransformation gives combination.
		/// </summary>
		/// <param name="combination">The two transformations combined.</param>
		/// <param name="secondTransformation">The transformation that when combined with the return value gives combination.</param>
		template<class TTransformer, class TVector>
		inline TTransformer DiscombineTransformations(const ITransformer<TTransformer, TVector>& combination, const TTransformer& secondTransformation)
		{
			return combination.DiscombineTransformations(secondTransformation);
		}
	}
} }