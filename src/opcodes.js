var opcodes =
    [
        {key: "iFail",
	 label: "i_fail",
	 args: []},
	{key: "iEnter",
	 label: "i_enter",
	 args: []},
        {key: "iExit",
	 label:"i_exit",
	 args: []},
	{key: "iExitFact",
	 label:"i_exitfact",
	 args: []},
        {key: "iExitQuery",
         label:"i_exitquery",
         args: []},
        {key: "iUserCall",
         label:"i_usercall",
         args: []},
        {key: "iCall",
	 label:"i_call",
	 args: ["functor"]},
        {key: "iCatch",
         label:"i_catch",
         args: ["slot"]},
        {key: "iSwitchModule",
         label:"i_switch_module",
         args: ["atom"]},
        {key: "bThrow",
         label:"b_throw",
         args: []},
        {key: "bCleanupChoicepoint",
         label:"b_cleanup_choicepoint",
         args: []},
        {key: "iExitModule",
         label:"i_exitmodule",
         args: []},
        {key: "iExitCatch",
         label:"i_exitcatch",
         args: ["slot"]},
        {key: "iDepart",
	 label:"i_depart",
	 args: ["functor"]},
	{key: "iCut",
	 label:"i_cut",
	 args: []},
        {key: "cCut",
         label:"c_cut",
         args: ["slot"]},
        {key: "cLCut",
         label:"c_lcut",
         args: ["slot"]},
        {key: "cIfThen",
         label:"c_ifthen",
         args: ["slot"]},
        {key: "cIfThenElse",
         label:"c_ifthenelse",
         args: ["slot", "address"]},
        {key: "iUnify",
	 label:"i_unify",
	 args: []},
	{key: "bFirstVar",
	 label: "b_firstvar",
	 args:["slot"]},
	{key: "bArgVar",
	 label: "b_argvar",
	 args: ["slot"]},
	{key: "bVar",
	 label: "b_var",
	 args: ["slot"]},
	{key: "bPop",
	 label: "b_pop",
	 args: []},
	{key: "bAtom",
	 label: "b_atom",
	 args: ["atom"]},
        {key: "bVoid",
         label: "b_void",
         args: []},
        {key: "bFunctor",
	 label: "b_functor",
	 args: ["functor"]},
	{key: "hAtom",
	 label: "h_atom",
	 args: ["atom"]},
	{key: "hFirstVar",
	 label: "h_firstvar",
	 args: ["slot"]},
	{key: "hFunctor",
	 label: "h_functor",
	 args: ["functor"]},
	{key: "hPop",
	 label: "h_pop",
	 args: []},
	{key: "hVoid",
	 label: "h_void",
	 args: []},
	{key: "hVar",
	 label: "h_var",
	 args: ["slot"]},
        {key: "tryMeOrNextClause",
         label: "try_me_or_next_clause",
         args: []},
        {key: "tryMeElse",
	 label: "try_me_else",
	 args: ["address"]},
	{key: "retryMeElse",
	 label: "retry_me_else",
	 args: ["address"]},
	{key: "trustMe",
	 label: "trust_me",
	 args: []},
	{key: "cJump",
	 label: "c_jump",
	 args: ["address"]},
	{key: "cOr",
	 label: "c_or",
	 args: ["address"]},
        {key: "iForeign",
         label: "i_foreign",
         args: ["foreign_function"]},
        {key: "iForeignRetry",
         label: "i_foreignretry",
         args: []},
	{key: "nop",
	 label: "nop",
	 args: []}
    ];

var map = {};

for (var i = 0; i < opcodes.length; i++)
{
    opcodes[i].opcode = i;
    map[opcodes[i].key] = opcodes[i];
}

module.exports = {opcodes:opcodes,
		  opcode_map: map};
