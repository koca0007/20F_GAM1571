#pragma once

namespace fw
{
	class Vector2
	{
	public:
		Vector2() { x = 0; y = 0; }
		Vector2(float ax, float ay) { x = ax; y = ay; }

		void SetX(float o) { x = o; }
		void SetY(float o) { y = o; }
		void SetXY(Vector2 o) { x = o.x, y = o.y; }

		Vector2 operator+(float o) const { return *this + o; }
		Vector2 operator-(float o) const { return *this - o; }
		Vector2 operator*(float o) const { return Vector2(x * o, y * o); }
		Vector2 operator/(float o) const { return *this / o; }

		Vector2 operator+=(float o) { x += o; y += o; return *this; }
		Vector2 operator-=(float o) { x -= o; y -= o; return *this; }
		Vector2 operator*=(float o) { x *= o; y *= o; return *this; }
		Vector2 operator/=(float o) { x /= o; y /= o; return *this; }

		Vector2 operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
		Vector2 operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
		Vector2 operator*(const Vector2& other) const { return Vector2(x * other.x, y * other.y); }
		Vector2 operator/(const Vector2& other) const { return Vector2(x / other.x, y / other.y); }

		Vector2 operator+=(const Vector2& o) { x += o.x; y += o.y; return *this; }
		Vector2 operator-=(const Vector2& o) { x -= o.x; y -= o.y; return *this; }
		Vector2 operator*=(const Vector2& o) { x *= o.x; y *= o.y; return *this; }
		Vector2 operator/=(const Vector2& o) { x /= o.x; y /= o.y; return *this; }




		float Length() { return sqrtf(SquaredLength()); }
		float SquaredLength() { return x * x + y * y; }

		void Normalize() {
			float length = SquaredLength();
			if (length != 0)
			{
				length = sqrtf(length);
				x /= length;
				y /= length;
			}
		}

		Vector2 Normalized()
		{
			Vector2 vec2 = Vector2(x, y);
			vec2.Normalize();
			return vec2;
		}

		float Distance(const Vector2& o) { return sqrtf(SquaredDistance(o)); }

		float SquaredDistance(const Vector2& o)
		{
			return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
		}

		float DotProduct(const Vector2& o) { return x * o.x + y * o.y; }

	public:
		float x = 0;
		float y = 0;


	};
}