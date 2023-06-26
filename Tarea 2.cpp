#pragma once
//usamos como partida su codigo en que nos mostro de ejmplo en el git y agremamos el main
#include <iostream>

template <typename T>
class Deque
{
private:
	T* InitialElement; // Puntero al arreglo que almacena los elementos
	int _head;
	int _tail;
	int _size;
	int _currentElements;
	bool _isDynamic;

public:
	Deque(int size, bool dynamic = true) : _size(size), _isDynamic(dynamic)
	{
		InitialElement = new T[_size];
		_head = 0;
		_tail = 0;
		_currentElements = 0;
	}

	~Deque()
	{
		delete[] InitialElement;
	}

	void EnqueueBack(T element)
	{
		if (Full())
		{
			if (_isDynamic)
			{
				T* auxPointer = new T[_size * 2]; // Crear un nuevo arreglo con el doble de tamaño
				for (int i = 0; i < _currentElements; i++)
				{
					auxPointer[i] = InitialElement[(i + _head) % _size]; // Copiar los elementos al nuevo arreglo
				}
				delete[] InitialElement;
				InitialElement = auxPointer;
				_size *= 2; // Actualizar el tamaño
				_head = 0;
				_tail = _currentElements;
			}
			else
			{
				std::cout << "Deque is full" << '\n';
				return;
			}
		}

		InitialElement[_tail] = element;
		_tail = (_tail + 1) % _size;
		_currentElements++; // Incrementar el número de elementos
	}

	void FrontDequeue()
	{
		if (Empty())
		{
			std::cout << "ERROR: Deque is empty. Underflow." << '\n';
			return;
		}

		_head = (_head + 1) % _size; // Mover la "cabeza" al siguiente elemento
		_currentElements--;

		if (_isDynamic && _currentElements <= _size / 4)
		{
			T* auxPointer = new T[_size / 2]; // Crear un nuevo arreglo con la mitad del tamaño actual
			for (int i = 0; i < _currentElements; i++)
			{
				auxPointer[i] = InitialElement[(i + _head) % _size]; // Copiar los elementos al nuevo arreglo
			}
			delete[] InitialElement;
			InitialElement = auxPointer;
			_size /= 2;
			_head = 0;
			_tail = _currentElements;
		}
	}

	void FrontEnqueue(T element)
	{
		if (Full())
		{
			if (_isDynamic)
			{
				T* auxPointer = new T[_size * 2];
				auxPointer[0] = element;
				for (int i = 1; i <= _currentElements; i++)
				{
					auxPointer[i] = InitialElement[(i - 1 + _head) % _size];
				}
				delete[] InitialElement;
				InitialElement = auxPointer;
				_size *= 2; // Actualizar el tamaño
				_head = 0;
				_tail = _currentElements + 1;
				_currentElements++;
			}
			else
			{
				std::cout << "Deque is full" << '\n';
				return;
			}
		}
		else
		{
			_head = (_head - 1 + _size) % _size;
			InitialElement[_head] = element;
			_currentElements++;
		}
	}

	void BackDequeue()
	{
		if (Empty())
		{
			std::cout << "ERROR: Deque is empty. Underflow." << '\n';
			return;
		}

		_tail = (_tail - 1 + _size) % _size;
		_currentElements--;

		if (_isDynamic && _currentElements <= _size / 4)
		{
			T* auxPointer = new T[_size / 2];
			for (int i = 0; i < _currentElements; i++)
			{
				auxPointer[i] = InitialElement[(i + _head) % _size]; // Copiar los elementos al nuevo arreglo
			}
			delete[] InitialElement; // Liberar memoria del arreglo original
			InitialElement = auxPointer; // Asignar el nuevo arreglo
			_size /= 2; // Actualizar el tamaño
			_head = 0;
			_tail = _currentElements;
		}
	}

	T Front()
	{
		if (Empty())
		{
			std::cout << "ERROR: Deque is empty. No front element." << '\n';
			return T();
		}

		return InitialElement[_head];
	}

	T Back()
	{
		if (Empty())
		{
			std::cout << "ERROR: Deque is empty. No back element." << '\n';
			return T();
		}

		return InitialElement[(_tail - 1 + _size) % _size];
	}

	bool Empty()
	{
		return _currentElements == 0;
	}

	bool Full()
	{
		return _size == _currentElements;
	}

	void Print()
	{
		if (Empty())
		{
			std::cout << "Deque is empty." << '\n';
			return;
		}

		for (int i = _head; i != _tail; i = (i + 1) % _size)
		{
			std::cout << InitialElement[i] << ", ";
		}
		std::cout << '\n';
	}
};

int main()
{
	Deque<int> deque(5);

	deque.EnqueueBack(1);
	deque.EnqueueBack(2);
	deque.EnqueueBack(3);
	deque.EnqueueBack(4);
	deque.EnqueueBack(5);
	deque.Print();

	deque.FrontEnqueue(6);
	deque.Print();

	deque.FrontEnqueue(7);
	deque.Print();

	deque.BackDequeue();
	deque.Print();

	int frontElement = deque.Front();
	std::cout << "Front element: " << frontElement << '\n';

	int backElement = deque.Back();
	std::cout << "Back element: " << backElement << '\n';

	return 0;
}