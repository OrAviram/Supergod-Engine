#pragma once

#include "IVector.h"
#include "../Interfaces/ITransformer.h"
#include "Vector2D.h"

namespace SupergodCore { namespace Math
{
	struct Vector4D;

	/// <summary>
	/// Represents a 3-component mathematical vector.
	/// </summary>
	struct SUPERGOD_API Vector3D final : public IVector<Vector3D>
	{
		#pragma region Presets for common vectors.
		/// <summary>
		/// Gets a 3D vector with all of its components set to 0.
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector3D, Zero, (0, 0, 0))

		/// <summary>
		/// Gets a 3D vector with all of its components set to 1.
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector3D, One, (1, 1, 1))

		/// <summary>
		/// Gets the 2D vector (1, 0, 0).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector3D, Right, (1, 0, 0))

		/// <summary>
		/// Gets the 2D vector (-1, 0, 0).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector3D, Left, (-1, 0, 0))

		/// <summary>
		/// Gets the 2D vector (0, 1, 0).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector3D, Up, (0, 1, 0))

		/// <summary>
		/// Gets the 2D vector (0, -1, 0).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector3D, Down, (0, -1, 0))

		/// <summary>
		/// Gets the 2D vector (0, 0, 1).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector3D, Forward, (0, 0, 1))

		/// <summary>
		/// Gets the 2D vector (0, 0, -1).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector3D, Back, (0, 0, -1))
		#pragma endregion

		union
		{
			struct { float x, y, z; };
			float components[3];
		};
	
		/// <summary>Creates a new 3D vector and initializes all of its components to 0.</summary>
		Vector3D();

		/// <summary>Creates a new 3D vector and initializes its components to x, y and z.</summary>
		Vector3D(float x, float y, float z);

		/// <summary>Creates a new 3D vector and initializes its x and y components to xy and its z component to z.</summary>
		Vector3D(const Vector2D& xy, float z);

		/// <summary>Creates a new 3D vector and initializes its x component x and its y and z components to yz.</summary>
		Vector3D(float x, const Vector2D& yz);

		/// <summary>
		/// Gets a reference to a component at the index of index.
		/// </summary>
		/// <param name="index">The index of the component (0, 1 or 2).</param>
		inline float& operator[](int index) override
		{
			return components[index];
		}

		/// <summary>
		/// Gets a reference to a component at the index of index.
		/// </summary>
		/// <param name="index">The index of the component (0, 1 or 2).</param>
		inline const float& operator[](int index) const override
		{
			return components[index];
		}

		/// <summary>
		/// Creates a new Vector2D with x and y as its components.
		/// </summary>
		explicit operator Vector2D() const;

		/// <summary>
		/// Creates a new Vector4D with x, y, z and 0 as its components.
		/// </summary>
		/// <returns></returns>
		operator Vector4D() const;
		
		/// /// <summary>
		/// Transform this vector by transformer.
		/// </summary>
		/// <returns>The transformed vector.</returns>
		template<class TTransformer>
		inline Vector3D Transform(const ITransformer<TTransformer, Vector3D> transformer) const
		{
			return transformer.TransformVector(*this);
		}

		#pragma region Axis Combinations.
		/// <summary>A Vector2D with the x and y components of this vector.</summary>
		inline Vector2D XY() const { return Vector2D(x, y); }

        /// <summary>A Vector2D with the y and x components of this vector.</summary>
		inline Vector2D YX() const { return Vector2D(y, x); }

        /// <summary>A Vector2D with the x and z components of this vector.</summary>
        inline Vector2D XZ() const { return Vector2D(x, z); }

        /// <summary>A Vector2D with the z and x components of this vector.</summary>
        inline Vector2D ZX() const { return Vector2D(z, x); }

        /// <summary>A Vector2D with the y and z components of this vector.</summary>
		inline Vector2D YZ() const { return Vector2D(y, z); }

        /// <summary>A Vector2D with the z and y components of this vector.</summary>
		inline Vector2D ZY() const { return Vector2D(z, y); }
		#pragma endregion

		#pragma region Comparison methods (Equals, ContainsComponent and CloseEnough).
		/// <summary>
		/// Is every component of this same as its corresponding component in other?
		/// </summary>
		bool Equals(const Vector3D& other) const override;

		/// <summary>
		/// Is every component of this close enough to its corresponding component in other with the threshold of threshold?<para/>
		/// See SupergodEngine::Math::Smath::CloseEnough.
		/// </summary>
		/// <param name="threshold">The threshold for each component to be considered close enough.</param>
		bool CloseEnough(const Vector3D& other, float threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const override;

		/// <summary>
		/// Does any component pass test?
		/// </summary>
		/// <param name="test">The test to run for each component.</param>
		bool ContainsComponent(const std::function<bool(float)>& test) const override;
		#pragma endregion

		#pragma region Addition, subtraction and negation.
		/// <summary>
		/// Adds every component of this with its corresponding component in other.
		/// </summary>
		Vector3D Add(const Vector3D& other) const override;

		/// <summary>
		/// Subtracts every component of other from its corresponding component in this.
		/// </summary>
		Vector3D Subtract(const Vector3D& other) const override;

		/// <summary>
		/// Negates every component of this.
		/// </summary>
		Vector3D Negated() const override;
		#pragma endregion

		#pragma region Multiplication (Dot, Multiply and Cross).
		/// <summary>
		/// Gets the dot product of this and other.
		/// </summary>
		float Dot(const Vector3D& other) const override;

		/// <summary>
		/// Multiplies this and other component-wise.
		/// </summary>
		Vector3D Multiply(const Vector3D& other) const override;

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		Vector3D Multiply(float scalar) const override;

		/// <summary>
		/// Gets the cross product of this and other.
		/// </summary>
		Vector3D Cross(const Vector3D& other) const;

		/// <summary>
		/// Gets the cross product of a and b.
		/// </summary>
		inline static Vector3D Cross(const Vector3D& a, const Vector3D& b)
		{
			return a.Cross(b);
		}
		#pragma endregion
		
		#pragma region Division.
		/// <summary>
		/// Divides every component of this by scalar.
		/// </summary>
		Vector3D Divide(float scalar) const override;

		/// <summary>
		/// Divides every component of this by its corresponding component in scalar.
		/// </summary>
		Vector3D Divide(const Vector3D& other) const override;
		#pragma endregion

		#pragma region BiggestComponent/BiggestComponent.
		/// <summary>
		/// Gets a reference to the biggest component in the vector.
		/// </summary>
		float& BiggestComponent() override;

		/// <summary>
		/// Gets a reference to the smallest component in the vector.
		/// </summary>
		float& SmallestComponent() override;

		/// <summary>
		/// Gets a reference to the biggest component in the vector.
		/// </summary>
		const float& BiggestComponent() const override;

		/// <summary>
		/// Gets a reference to the smallest component in the vector.
		/// </summary>
		const float& SmallestComponent() const override;
		#pragma endregion

		#pragma region Clamping methods.
		/// <summary>
		/// Gets a vector where all of its components are the absolute value of their corresponding component in this.
		/// </summary>
		/// <returns></returns>
		Vector3D Abs() const override;

		/// <summary>
		/// Clamps every component of this so it's never smaller than its corresponding component in min and never bigger than its corresponding component in max.
		/// </summary>
		Vector3D Clamp(const Vector3D& min, const Vector3D& max) const override;

		/// <summary>
		/// Clamps every component of this so it's never smaller than min and never bigger than max.
		/// </summary>
		Vector3D ClampComponents(float min, float max) const override;
		#pragma endregion
	};
} }