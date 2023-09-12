#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	for (int i = 0; i < 4; i++) {
		this->slots[i] = other.slots[i];
	}
}

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator = ( const MateriaSource& other )
{
	for (int i = 0; i < 4; i++) {
		this->slots[i] = other.slots[i];
	}
	return (*this);
}

// AMateria에 해당하는 ice or Cure를 저장
void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (!this->slots[i])
			slots[i] = m;
	}
}

// stirng에 해당하는 ice or Cure를 반환
AMateria* MateriaSource::createMateria(std::string const & type)
{

}
