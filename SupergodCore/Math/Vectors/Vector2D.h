#pragma once

#include "IVector.h"

namespace SupergodCore { namespace Math
{
	struct Vector3D;
	struct Vector4D;

	/// <summary>
	/// Represents a 2-component mathematical vector.
	/// </summary>
	struct SUPERGOD_API Vector2D final : public IVector<Vector2D>
	{
		#pragma region Presets for common vectors.
		/// <summary>
		/// Gets a 2D vector with all of its components set to 0.
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector2D, Zero, (0, 0))
		
		/// <summary>
		/// Gets a 2D vector with all of its components set to 1.
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector2D, One, (1, 1))
		
		/// <summary>
		/// Gets the 2D vector (0, 1).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector2D, Up, (0, 1))
		
		/// <summary>
		/// Gets the 2D vector (0, -1).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector2D, Down, (0, -1))
		
		/// <summary>
		/// Gets the 2D vector(1, 0).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector2D, Right, (1, 0))
		
		/// <summary>
		/// Gets the 2D vector (-1, 0).
		/// </summary>
		DEFINE_STRUCT_VALUE_PRESET(Vector2D, Left, (-1, 0))
		#pragma endregion

		union
		{
			struct { float x, y; };
			float components[2];
		};
		
		/// <summary>Creates a new 2D vector and initializes both of its components to 0.</summary>
		Vector2D();

		/// <summary>Creates a new 2D vector and initializes its components to x and y.</summary>
		Vector2D(const float& x, const float& y);

		/// <summary>
		/// Gets a reference to a component at the index of index.
		/// </summary>
		/// <param name="index">The index of the component (0 or 1).</param>
		inline float& operator[](int index)
		{
			return components[index];
		}

		/// <summary>
		/// Gets a reference to a component at the index of index.
		/// </summary>
		/// <param name="index">The index of the component (0 or 1).</param>
		inline const float& operator[](int index) const
		{
			return components[index];
		}

		/// <summary>
		/// Creates a new Vector3D that uses the x and y components of this and sets z to 0.
		/// </summary>
		operator Vector3D() const;

		/// <summary>
		/// Creates a new Vector4D that uses the x and y components of this and sets the other components to 0.
		/// </summary>
		operator Vector4D() const;

		#pragma region Comparison methods (Equals, ContainsComponent and CloseEnough).
		/// <summary>
		/// Is every component of this same as its corresponding component in other?
		/// </summary>
		bool Equals(const Vector2D& other) const override;

		/// <summary>
		/// Is every component of this close enough to its corresponding component in other with the threshold of threshold?<para/>
		/// See SupergodEngine::Math::Smath::CloseEnough.
		/// </summary>
		/// <param name="threshold">The threshold for each component to be considered close enough.</param>
		bool CloseEnough(const Vector2D& other, const float& threshold = Constants::CLOSE_ENOUGH_DEFAULT_THRESHOLD) const override;

		/// <summary>
		/// Does any component pass test?
		/// </summary>
		/// <param name="test">The test to run for each component.</param>
		bool ContainsComponent(const std::function<bool(const float&)>& test) const override;
		#pragma endregion

		#pragma region Addition, subtraction and negation.
		/// <summary>
		/// Adds every component of this with its corresponding component in other.
		/// </summary>
		Vector2D Add(const Vector2D& other) const override;

		/// <summary>
		/// Subtracts every component of other from its corresponding component in this.
		/// </summary>
		Vector2D Subtract(const Vector2D& other) const override;
		
		/// <summary>
		/// Negates every component of this.
		/// </summary>
		Vector2D Negated() const override;
		#pragma endregion

		#pragma region Multiplication (Dot and Multiply).
		/// <summary>
		/// Gets the dot product of this and other.
		/// </summary>
		float Dot(const Vector2D& other) const override;

		/// <summary>
		/// Multiplies this and other component-wise.
		/// </summary>
		Vector2D Multiply(const Vector2D& other) const override;

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		Vector2D Multiply(const float& scalar) const override;
		#pragma endregion

		#pragma region Division.
		/// <summary>
		/// Divides every component of this by scalar.
		/// </summary>
		Vector2D Divide(const float& scalar) const override;

		/// <summary>
		/// Divides every component of this by its corresponding component in scalar.
		/// </summary>
		Vector2D Divide(const Vector2D& other) const override;
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
		Vector2D Abs() const override;

		/// <summary>
		/// Clamps every component of this so it's never smaller than its corresponding component in min and never bigger than its corresponding component in max.
		/// </summary>
		Vector2D Clamp(const Vector2D& min, const Vector2D& max) const override;

		/// <summary>
		/// Clamps every component of this so it's never smaller than min and never bigger than max.
		/// </summary>
		Vector2D ClampComponents(const float& min, const float& max) const override;
		#pragma endregion
	};
} }