/*
 * BIT_MATH.h
 *
 *  Created on: Sep 7, 2023
 *      Author: m
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,POS)       			 (REG|=(1<<POS))
#define CLEAR_BIT(REG,POS)    			 (REG&=~(1<<POS))
#define TOGGLE_BIT(REG,POS)    			 (REG^=(1<<POS))
#define GET_BIT(REG,POS)      			 (REG=(REG>>POS)&0x01)

#define READ_REG(REG)          			 (REG)
#define WRITE_REG(REG,VALUE)             ((REG)=(VALUE))

#define MODIFY_REG(REG,BIT_MASK,VALUE,BITS_POS)   WRITE_REG(REG,((REG)&(~(BIT_MASK)))|VALUE<<BITS_POS)

#define CIRCULAR_SHIFTING(reg,n_of_shift,reg_size)					reg=((reg<<n_of_shift)|(reg>>(reg_size-n_of_shift)))

#endif /* BIT_MATH_H_ */
