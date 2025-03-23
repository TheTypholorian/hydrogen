#include <functional>
#include <vector>
#include <forward_list>
#include <sstream>

using namespace std;

namespace H {
	template <typename T>
	class Rect2D {
	private:
		T x, y, w, h;

	public:
		forward_list<function<void(Rect2D<T>)>> listeners;

		Rect2D(T x = 0, T y = 0, T w = 0, T h = 0) : x(x), y(y), w(w), h(h) {
		}

	protected:
		virtual void update() {
			for (auto l : listeners) {
				l(*this);
			}
		}

	public:
		T getX() const {
			return x;
		}

		void setX(T x) {
			this->x = x;
			update();
		}

		T getY() const {
			return y;
		}

		void setY(T y) {
			this->y = y;
			update();
		}

		T getW() const {
			return w;
		}

		void setW(T w) {
			this->w = w;
			update();
		}

		T getH() const {
			return h;
		}

		void setH(T h) {
			this->h = h;
			update();
		}

		void set(T x, T y, T w, T h) {
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
			update();
		}

		void setXY(T x, T y) {
			this->x = x;
			this->y = y;
			update();
		}

		void setWH(T w, T h) {
			this->w = w;
			this->h = h;
			update();
		}

		T area() const {
			return w * h;
		}

		bool contains(T x, T y) {
			T x0 = getX(), y0 = getY();
			return x >= x0 &&
				y >= y0 &&
				x < x0 + getW() &&
				y < y0 + getH();
		}

		string toString() const {
			ostringstream s;
			s << "[" << x << ", " << y << ", " << w << ", " << h << "]";
			return s.str();
		}

		T operator[](int i) const {
			switch (i) {
			case 0: {
				return x;
			}
			case 1: {
				return y;
			}
			case 2: {
				return w;
			}
			case 3: {
				return h;
			}
			};
		}

		bool operator==(const Rect2D<T>& rect) const {
			return x == rect.x && y == rect.y && w == rect.w && h == rect.h;
		}

		bool operator!=(const Rect2D<T>& rect) const {
			return x != rect.x && y != rect.y && w != rect.w && h != rect.h;
		}

		bool operator>(const Rect2D<T>& rect) const {
			return area() > rect.area();
		}

		bool operator<(const Rect2D<T>& rect) const {
			return area() < rect.area();
		}

		bool operator>=(const Rect2D<T>& rect) const {
			return area() >= rect.area();
		}

		bool operator<=(const Rect2D<T>& rect) const {
			return area() <= rect.area();
		}

		Rect2D<T>& operator+=(const Rect2D<T>& rect) {
			x += rect.x;
			y += rect.y;
			update();
			return *this;
		}

		Rect2D<T>& operator+=(T t) {
			x += t;
			y += t;
			update();
			return *this;
		}

		Rect2D<T>& operator-=(const Rect2D<T>& rect) {
			x -= rect.x;
			y -= rect.y;
			update();
			return *this;
		}

		Rect2D<T>& operator-=(T t) {
			x -= t;
			y -= t;
			update();
			return *this;
		}

		Rect2D<T>& operator*=(const Rect2D<T>& rect) {
			x *= rect.x;
			y *= rect.y;
			w *= rect.w;
			h *= rect.h;
			update();
			return *this;
		}

		Rect2D<T>& operator*=(T t) {
			x *= t;
			y *= t;
			w *= t;
			h *= t;
			update();
			return *this;
		}

		Rect2D<T>& operator/=(const Rect2D<T>& rect) {
			x /= rect.x;
			y /= rect.y;
			w /= rect.w;
			h /= rect.h;
			update();
			return *this;
		}

		Rect2D<T>& operator/=(T t) {
			x /= t;
			y /= t;
			w /= t;
			h /= t;
			update();
			return *this;
		}

		Rect2D<T>& operator%=(const Rect2D<T>& rect) {
			x %= rect.x;
			y %= rect.y;
			w %= rect.w;
			h %= rect.h;
			update();
			return *this;
		}

		Rect2D<T>& operator%=(T t) {
			x %= t;
			y %= t;
			w %= t;
			h %= t;
			update();
			return *this;
		}

		Rect2D<T>& operator+(const Rect2D<T>& rect) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n += rect;
			return *n;
		}

		Rect2D<T>& operator+(T t) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n += t;
			return *n;
		}

		Rect2D<T>& operator-(const Rect2D<T>& rect) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n -= rect;
			return *n;
		}

		Rect2D<T>& operator-(T t) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n -= t;
			return *n;
		}

		Rect2D<T>& operator*(const Rect2D<T>& rect) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n *= rect;
			return *n;
		}

		Rect2D<T>& operator*(T t) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n *= t;
			return *n;
		}

		Rect2D<T>& operator/(const Rect2D<T>& rect) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n /= rect;
			return *n;
		}

		Rect2D<T>& operator/(T t) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n /= t;
			return *n;
		}

		Rect2D<T>& operator%(const Rect2D<T>& rect) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n %= rect;
			return *n;
		}

		Rect2D<T>& operator%(T t) {
			Rect2D<T>* n = new Rect2D<T>(x, y, w, h);
			n %= t;
			return *n;
		}
	};
}