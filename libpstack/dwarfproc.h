#ifndef PSTACK_DWARFPROC_H
#define PSTACK_DWARFPROC_H

#include <stack>
typedef std::stack<Elf_Addr> DwarfExpressionStack;
Elf_Addr dwarfGetCFA(DwarfInfo *dwarf, const Process &proc, const DwarfCallFrame *frame, const DwarfRegisters *regs);
uintmax_t dwarfGetReg(const DwarfRegisters *regs, int regno);
void dwarfSetReg(DwarfRegisters *regs, int regno, uintmax_t regval);
DwarfRegisters *dwarfPtToDwarf(DwarfRegisters *dwarf, const CoreRegisters *sys);
const DwarfRegisters *dwarfDwarfToPt(CoreRegisters *sys, const DwarfRegisters *dwarf);
bool dwarfUnwind(Process &, const StackFrame *in, StackFrame *out, Elf_Addr *cfa);
Elf_Addr dwarfEvalExpr(DwarfInfo *, const Process &proc, DWARFReader &r, const StackFrame *frame, DwarfExpressionStack *stack);
Elf_Addr dwarfEvalExpr(const Process &, const DwarfAttribute *, const StackFrame *, DwarfExpressionStack *stack);

#endif // PSTACK_DWARFPROC_H
