#include "cpu/exec/template-start.h"

#define instr lgdt

static void do_execute () {
	printf ("%x\n",op_src->addr);
	if (op_src->size == 2)
	{
		cpu.GDTR.gdl = swaddr_read (op_src->addr,2);
		cpu.GDTR.gda = swaddr_read (op_src->addr + 16,3);
	}
	else if (op_src->size == 4)
	{
		cpu.GDTR.gdl = swaddr_read (op_src->addr,2);
		cpu.GDTR.gda = swaddr_read (op_src->addr + 16,4);
	}
	printf ("gdl = 0x%x gda = 0x%x\n",cpu.GDTR.gdl,cpu.GDTR.gda);
	print_asm_template1();
}
make_instr_helper(rm)


#include "cpu/exec/template-end.h"
