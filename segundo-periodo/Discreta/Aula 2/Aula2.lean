-- Bernardo Cavanellas Biondini
-- Matrícula 20.1.4112

variables P Q R S T: Prop.

lemma exA (H1: (P ∧ Q) ∧ R)(H2: S ∧ T) : Q ∧ S :=

  and.intro(and.elim_right (and.elim_left H1))
           (and.elim_left H2).

lemma exC (H1: P)(H2: P → (P → Q)) : Q :=

    show Q,
    from (H2 H1 (show P, 
            from (H1))).

lemma exD : (P ∧ Q) → P :=

    assume H : P ∧ Q,
    (and.elim_left H).

lemma exE (H1 : P): Q → P ∧ Q :=

    assume H: Q,
    show P ∧ Q, 
    from(and.intro H1 H).