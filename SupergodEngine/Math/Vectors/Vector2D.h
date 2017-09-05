#pragma once

#include "IVector.h"

namespace SupergodEngine { namespace Math
{
	/// <summary>
	/// Represents a 2-component mathematical vector.
	/// </summary>
	struct SUPERGOD_API Vector2D final : public IVector<Vector2D>
	{
		union
		{
			struct { float x, y; };
			float components[2];
		};
		
		/// <summary>Creates a new 2D vector and initializes both of its components to 0.</summary>
		Vector2D();

		/// <summary>Creates a new 2D vector and initializes its components to x and y.</summary>
		explicit Vector2D(const float& x, const float& y);

		#pragma region Comparison methods (Equals, operators, ContainsComponent, CloseEnough).
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
		bool ContainsComponent(std::function<bool(const float&)> test) const override;
		
		/// <summary>
		/// Is every component of this the same as its corresponding component in other?
		/// </summary>
		bool operator==(const Vector2D& other) const;

		/// <summary>
		/// Are any of the components of this NOT equal to their corresponding component in other?
		/// </summary>
		bool operator!=(const Vector2D& other) const;
		#pragma endregion

		#pragma region Magnitude, squared magnitude and normalization.
		/// <summary>
		/// Gets the magnitude (length) of this vector.
		/// </summary>
		float Magnitude() const override;
		
		/// <summary>
		/// Gets the squared magnitude (length) of this vector. This is faster than squaring the magnitude.
		/// </summary>
		float SqrMagnitude() const override;
		
		/// <summary>
		/// Gets a unit vector pointing in the same direction of this vector.
		/// </summary>
		Vector2D Normalized() const override;
		#pragma endregion

		#pragma region Multiplication (Dot, Multiply, and the operators).
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

		/// <summary>
		/// Multiplies this and other component-wise.
		/// </summary>
		Vector2D operator*(const Vector2D& other) const;

		/// <summary>
		/// Multiplies every component of this by scalar.
		/// </summary>
		Vector2D operator*(const float& scalar) const;

		/// <summary>
		/// Multiplies every component of vector by scalar.
		/// </summary>
		friend Vector2D operator*(const float& scalar, const Vector2D& vector)
		{
			return vector * scalar;
		}
		#pragma endregion

		// TODO: Implement and document those.
		#pragma region Division.
		Vector2D Divide(const float& scalar) const override;
		Vector2D Divide(const Vector2D& scalar) const override;
		#pragma endregion

		#pragma region Those methods are here just so it will compile. I will organize and implement them later.
		Vector2D Abs() const override;

		Vector2D Clamp(const Vector2D & min, const Vector2D & max) const override;

		Vector2D Add(const Vector2D & other) const override;

		Vector2D Subtract(const Vector2D & other) const override;

		Vector2D Negated() const override;

		const float & BiggestComponent() const override;

		const float & SmallestComponent() const override;

		Vector2D ClampComponents(const float & min, const float & max) const override;
		#pragma endregion
	};
} }