#pragma once
#include "Common/CommonDefines.h"

namespace SupergodCore { namespace Math
{
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
		inline TVector TransformVector(const TVector& vector, const TTransformer& transformer)
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
		inline TVector TransformVector(const TTransformer, TVector& transformer, const TVector& vector)
		{
			return TransformVector(vector, transformer);
		}

		/// <summary>
		/// Combines original with transformer.
		/// </summary>
		/// <param name="original">The first transform.</param>
		/// <param name="transformer">The transform to combine original with.</param>
		/// <returns>A combination of original and transformer.</returns>
		template<class TTransformer>
		inline TTransformer CombineTransformations(const TTransformer& original, const TTransformer& transformer)
		{
			return original.CombineTransformations(transformer);
		}

		/// <summary>
		/// Returns the transformation that when combined with secondTransformation gives combination.
		/// </summary>
		/// <param name="combination">The two transformations combined.</param>
		/// <param name="secondTransformation">The transformation that when combined with the return value gives combination.</param>
		template<class TTransformer>
		inline TTransformer DiscombineTransformations(const TTransformer& combination, const TTransformer& secondTransformation)
		{
			return combination.DiscombineTransformations(secondTransformation);
		}
	}
} }