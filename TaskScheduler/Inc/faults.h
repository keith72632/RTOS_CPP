/*
 * faults.h
 *
 *  Created on: Dec 30, 2021
 *      Author: khorton
 */

#ifndef FAULTS_H_
#define FAULTS_H_


#include <stdio.h>

namespace Faults {
	void enable_faults();
	void gen_usage_fault();
	void gen_memory_fault();
}


#endif /* FAULTS_H_ */
